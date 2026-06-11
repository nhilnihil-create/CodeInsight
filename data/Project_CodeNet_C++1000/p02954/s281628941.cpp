#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

vector<ll> A{0};
vector<ll> B;
map<ll, ll> Ans;
ll L, j = 1;
string S, T;

int main(){
cin >> T;

S = 'a' + T;

L = S.size();B.resize(L + 1);

rep(i, 1, L - 1){

  if(S[i] == 'R' &&S[i + 1] == 'L')A.push_back(i + 1);

}

rep(i, 1, L){

  if(i < A[j]){

    if(S[i] == 'R'){

      B[i] = A[j] - i;continue;

    }

    if(S[i] == 'L'){

      B[i] = i - A[j - 1];continue;

    }
  }

  if(i == A[j]){
    
    if(j <= A.size() - 1)j++;
    
    continue;
    
    }

    if(i > A.back()){B[i] = i - A.back();continue;}

}

j = 1;

rep(i, 1, L){

    if(i == A[j]){
    
    if(j > A.size() - 1)break;
      
    Ans[A[j]]++;
    
    j++;continue;
    
    }

  if(S[i] == 'R'){

    if(B[i]%2 == 0){Ans[A[j]]++;continue;}

    if(B[i]%2 == 1){Ans[A[j] - 1]++;continue;}

  }

  if(S[i] == 'L'){

    if(B[i]%2 == 0){Ans[A[j - 1]]++;continue;}

    if(B[i]%2 == 1){Ans[A[j - 1] - 1]++;continue;}

  }

}
  
rep(i, 1, L){cout << Ans[i] << " ";}

}