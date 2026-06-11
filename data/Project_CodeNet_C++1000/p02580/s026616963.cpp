#include <bits/stdc++.h>
using namespace std;

int main() {
  long H,W,M;
  cin>>H>>W>>M;
  vector<long>K(M);//これは問題文の配列「h」
  vector<long>O(M);//これは問題文の配列「w」
  long h=H+1;//添え字は0を含むので+1
  long w=W+1;
  int m=max(h,w);//面倒なので大きい方を取る
  vector<long>A(m,0);//配列「h」のK行に存在する爆弾の数を記録する表
  vector<long>B(m,0);//配列「w」のO列に存在する爆弾の数を記録する表
  vector<long>a(m,0);//表Aのコピー
  vector<long>b(m,0);//表Bのコピー
  vector<long>D(m,0);//表Aのコピー
  vector<long>d(m,0);//表Bのコピー
  for(long i=0;i<M;i++){
    cin>>K[i]>>O[i];
    A[K[i]]++;//点数表のK[i]番目にK[i]行に１つ爆弾があることを記録する。
    B[O[i]]++;//点数表のO[i]番目にO[i]列に１つ爆弾があることを記録する。
    a[K[i]]++;//コピー
    b[O[i]]++;//コピー
    D[K[i]]++;//コピー
    d[O[i]]++;//コピー
  }
  long C=0;
  long c=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());//ここで一番点数の高い添え字をa[0]に持ってくる。
  for(long i=0;i<m;i++){
    if(a[0]==D[i]){
      c=i;//ここでa[0]が何番目の添え字だったのかを記録する。
      break;
    }
  }//ここまでの作業で配列「h」の中で爆弾一番多いK行の内の１つの添え字を特定し、cに保存できた。
  for(long i=0;C<a[0];i++){
    if(K[i]==c){
      b[O[i]]--;//ここで配列「h」のK行のc番目と添え字が同じ配列「w」のO列全てを抹消する。
      C++;
    }
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());//ここで一番点数の高い添え字をb[0]に持ってくる。
  int ANS=a[0]+b[0];//これで配列「h」に存在する爆弾の最大行と、
  //それと重複しない配列「w」に存在する爆弾の最大列をANSに記録できた。
  //ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
  //以下はこれで配列「w」に存在する爆弾の最大行と、
  //それと重複しない配列「h」に存在する爆弾の最大列をansに記録するもの。
  long E=0;
  sort(B.begin(),B.end());
  reverse(B.begin(),B.end());
  for(long i=0;i<m;i++){
    if(B[0]==d[i]){
      c=i;
      break;
    }
  }
  for(int i=0;E<B[0];i++){
    if(O[i]==c){
      A[K[i]]--;
      E++;
    }
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int ans=A[0]+B[0];
  
  cout<<max(ANS,ans)<<endl;
}