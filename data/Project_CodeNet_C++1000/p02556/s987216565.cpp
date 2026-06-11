  #include <bits/stdc++.h>
   
  #define TRACE(x) cerr << #x << " = " << x << endl
  #define pb push_back
  #define mp make_pair
  #define fi first
  #define se second
   
  #define SZ(x) (int)(x).size()
   
  using namespace std;
   
  typedef unsigned long long ll;
  typedef pair<int, int> pii;
   
  template<class Num>
  Num mabs(Num A){
    if(A < 0) return -A;
    return A;
  }
  
  const int N = 2e5 + 10;
  
  int n;
  pii cord[N];
  int suma[N], razxy[N], razyx[N];
  
  int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
      scanf("%d %d", &cord[i].fi, &cord[i].se);
    }
    
    sort(cord, cord + n);
    
    for(int i = 0; i < n; i++){
      suma[i] = cord[i].fi + cord[i].se;
      razxy[i] = cord[i].fi - cord[i].se;
      razyx[i] = cord[i].se - cord[i].fi;
    }
    
    sort(suma, suma + n);
    sort(razxy, razxy + n);
    sort(razyx, razyx + n);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
      ans = suma[n - 1] - suma[i];
      ans = max(ans, razyx[i] + razxy[i]);
      ans = max(ans, razxy[i] + razyx[n - 1]);
      ans = max(ans, suma[i] - suma[0]);
    }
    
    printf("%d\n", ans);
    
    return 0;
  }
