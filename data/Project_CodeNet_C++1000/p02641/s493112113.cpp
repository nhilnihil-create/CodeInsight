#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
  int x,n,p;
  vector<int> d(102);//あるかないかの配列 0~101までの102個
 cin>>x>>n;
  rep(i,n){
  cin>>p;
d[p]=1;//p[i]に含まれている数字にたいしては1を格納
  }
  int ans=102;//絶対値を格納
  int ans1=0;//数字を格納
  for(int i=0;i<102;i++){//d[p]の要素数の分だけループを回す
 /*if(p[i]<x){//何もしない
 
  } */ 
    if (d[i]==1) continue;//入っていたらcontinue
    else if(ans==abs(x-i)){//ansと今の絶対値が一緒だったら、前のやつが答え
    
      break;
    }
    else if(ans>abs(x-i)){//更新される場合
   ans=min(ans,abs(x-i));//小さい方をansに
   ans1=i;//答えを更新
   
    }

}
 cout<<ans1<<endl; 
}
  
  