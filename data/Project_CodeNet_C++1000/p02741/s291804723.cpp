#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int k[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int x; cin>>x;
	cout<<k[x-1]<<endl;
	return 0;
}
