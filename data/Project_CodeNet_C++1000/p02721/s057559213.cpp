#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define inputInt(a) int a; cin >> a; 
#define inputInt2(a,b) int a; int b; cin >> a >> b; 
#define inputInt3(a,b,c) int a; int b; int c; cin >> a >> b >> c;
#define inputLong(a) long a;cin >> a; 
#define inputIntArray(a,N) int a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputLongArray(a,N) long a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputIntArray2(a,b,N) int a[N]; int b[N]; for(int i=0;i<N;i++){cin >> a[i] >> b[i];}
#define output(answer) cout << answer << endl;
#define fN(i,N)    for(int i=0; i<N; i++)
#define fSE(i,s,e) for(int i=s; i<=e; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,N) for(int i=0; i<N; i++)
#define cinv(v,N) vector<int> v(N); for(int i=0; i<N; i++){ cin >> v[i]; }
#define mt make_tuple
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define all(v) (v).begin(),(v).end()
const ll MOD2 = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N, K, C; cin >> N >> K >> C;
  string S; cin >> S;
  
  //main
  vll left(N+2,0), right(N+2,0), ldleft(N+2,-1e18), ldright(N+2,1e18);
  
  bool flag = true; ll count = 0; ll tmp = -1e18;
  for(int i=1; i<=N; i++){
    if(S[i-1] == 'o' && flag){
      left[i] = left[i-1]+1; 
      flag = false; count = C;
      ldleft[i] = i; tmp = i;
    }else{
      if(count > 1){//休んでいない。
        count --;
      }else if(count == 1){//休みきった。
        count --; flag = true; 
      }
      left[i] = left[i-1];
      ldleft[i] = tmp;
    }
  }
  
  flag = true; count = 1e18; tmp = 1e18;
  for(int i=N; i>=1; i--){
    if(S[i-1] == 'o' && flag){
      right[i] = right[i+1]+1; 
      flag = false; count = 0;
      ldright[i] = i; tmp = i;
    }else{
      if(count < C-1){//休んでいない。
        count ++;
      }else if(count == C-1){//休みきった。
        count ++; flag = true; 
      }
      right[i] = right[i+1]; 
      ldright[i] = tmp;
    }
  }
  
  
  // output
  /*ll ans = 0;
  for(int i=1; i<=N; i++){ cout << left[i] << " " << right[i] << endl;}*/
  if(C != 0){
    for(int i=1; i<=N; i++){
      if((left[i-1]+right[i+1]) == K-1 && (ldright[i+1]-ldleft[i-1])>=C+1  && S[i-1] == 'o'){
        cout << i << endl; 
      }
    }
  }else{
    ll cnt = 0;
    FOR(i,N){ if(S[i]=='o') cnt ++; } 
    if(cnt==K){
      FOR(i,N){ 
        if(S[i]=='o'){
          cout << i+1 << endl; 
        }
      } 
    }else{
       
    }
  }
  
  //FOR(i,N+2){ cout << ldleft[i]; } cout << endl;
  //FOR(i,N+2){ cout << ldright[i]; } cout << endl;

  return 0;
}