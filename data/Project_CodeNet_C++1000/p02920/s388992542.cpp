#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int in;
    int n;cin >> n;
    multiset<int> s;
    for(int i = 0; i < (1 << n); i++){
        cin >> in;
        s.insert(in);
    }
    int back = *s.rbegin();
    s.erase(--s.end());
    vi vec; 
    vec.pb(back);
    for(int i =1; i <= n; i++){
       vi toAdd;
       for(int x: vec){
          auto it = s.lower_bound(x);
          if(it == s.begin()){
            cout << "No" <<endl;
            return 0;
          }
          it--;
          toAdd.pb(*(it));
          s.erase(it);
       } 
       vec.insert(vec.end(), toAdd.begin(), toAdd.end());
    }

    cout << "Yes" <<endl;


}


