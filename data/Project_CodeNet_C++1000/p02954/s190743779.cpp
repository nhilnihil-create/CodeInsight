#include <iostream>
 
using namespace std;


int main(){
  string S;
  cin >> S;
  int N = S.size();
  int ans[N];

  for(int i=0; i<N; i++){
    ans[i] = 0;
  }

  int p=0,l=0;
  for(int i=0; i<N-1; i++){ 
    if(S[i]=='R' && S[i+1]=='L'){
      l = i - p;
      if(l==0){
        ans[i] += 1;
      }else if(l%2==0){
        ans[i] += l / 2 + 1;
        ans[i+1] += l / 2;
      }else{
        ans[i] += l / 2 + 1;
        ans[i+1] += l / 2 + 1;
      }
      p = i;
    }else if(S[i]=='L'){
      p = i + 1;
    }
  }

  p = N-1;
  for(int i=N-1; i>0; i--){ 
    if(S[i]=='L' && S[i-1]=='R'){
      l = p - i;
      if(l==0){
        ans[i] += 1;
      }else if(l%2==0){
        ans[i] += l / 2 + 1;
        ans[i-1] += l / 2;
      }else{
        ans[i] += l / 2 + 1;
        ans[i-1] += l / 2 + 1;
      }
      p = i;
    }else if(S[i]=='R'){
      p = i - 1;
    }
  }

  for(int i=0; i<N; i++){
    cout << ans[i] << " ";
  }
  cout << endl;
}
