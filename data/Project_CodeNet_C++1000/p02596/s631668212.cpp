#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>  
#include<set>
#include<iterator>
#include<list>
#include<utility>
#include<cstdlib>
#include<queue>
#include<stack>
#include<bitset>
//#include<bits/stdc++.h>
#define PI  2*acos(0.0)
#define pb push_back

       
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;



int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0), cout.tie(0);

ll n;

cin>>n;

if(n%2==0 || n%5==0) cout<<"-1"<<endl;
else
{
	ll sum = 0;
	ll ans;
    for (ans = 1; ans <= n; ans++) {
      sum = (sum * 10 + 7) % n;
      if (sum == 0) break;
    }
    cout << ans << endl;
		
}

	
	
	return 0;
	
	
	       /***Israil Hosen
	            Computer Science & Engineering
	         University Of Rajshahi.
	         ***/
	
	
	
}