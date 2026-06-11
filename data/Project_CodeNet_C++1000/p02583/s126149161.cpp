#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define N 500005
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
   int n; cin >> n;
   int A[n];
   for(int i = 0; i < n; i++){
     cin >> A[i];
   }
   sort(A, A + n);
   int res = 0;
   for(int i = 0; i < n; i++){
     for(int j = i + 1; j < n; j++){
       for(int k = j + 1; k < n; k++){
         set < int > s;
         s.insert(A[i]);
         s.insert(A[j]);
         s.insert(A[k]);
         if(A[i] + A[j] > A[k] && (int)s.size() == 3) res++;
       }
     }
   }
   
   cout << res;
  
  
}

int32_t main(){
	IOS;
	int tt = 1; 
	//cin >> tt;
	while(tt--){
    test_case();
    cout << endl;
	}
	return 0;
}
