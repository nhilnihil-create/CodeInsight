#include<iostream>

using namespace std;

bool judge(int A,int B,int C){
  if(A >= B+C) return false;
  else if(B >= C+A) return false;
  else if(C >= A+B) return false;
  else if(A == B) return false;
  else if(B == C) return false;
  else if(C == A) return false;
  else return true;
}

int main(void){
  int N,ans = 0;

  cin >> N;
  if(N < 3){
    cout << '0' << endl;
    return 0;
  }

  int L[N];

  for(int i = 0;i < N;i++){
    cin >> L[i];
  }

  for(int i = 0;i < N-2;i++){
    for(int j = i+1;j < N-1;j++){
      for(int k = j+1;k < N;k++){
        if(judge(L[i],L[j],L[k]))
          ans++;
      }
    }
  }

  cout << ans << endl;
}
