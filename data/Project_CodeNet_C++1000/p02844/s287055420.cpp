#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; int N; int count;
  cin >> N >> S;
  for (int i=0;i<1000;i++){
    int a[3]={i/100, (i/10)%10, i%10};
    // 100の桁、10の桁、1の桁
    int kakutei=0;
    for (int j=0; j<N;j++){
      if(S[j]==('0'+a[kakutei])){
        kakutei++;
      }
        //a[0]と同じ文字があれがa[1]を探しに行く
        if(kakutei==3){
          break;
        }
    }
        if(kakutei==3){
          count++;
        }
    
  }
    cout << count << endl;
  }