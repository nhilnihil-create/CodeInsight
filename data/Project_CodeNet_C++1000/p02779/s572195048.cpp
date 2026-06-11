#include <iostream>
using namespace std;
#include <bits/stdc++.h>


#define endl "\n"
#define pi                 3.1415926535897932384626433832795
#define ll                 long long
#define pb                 push_back
#define pii                pair < int , int >
#define vecsort(v)         sort(v.begin(),v.end())
#define lcm(x,y)           (x/__gcd(x,y))*y
#define vecsum(v)          accumulate(v.begin(), v.end(), 0)
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

long long a[200005];
int main(){

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n ;
    cin >> n ;
    set < long long > s;
    for( int i = 0 ; i < n ; i++){
       cin >> a[i];
       s.insert(a[i]);
    }
    if( s.size() == n ){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


	return 0;

}