#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   	int m1,d1,m2,d2;
   	cin >> m1 >> d1 >> m2 >> d2;
   	map<int,int> m;
   	m[1]=31;m[2]=28;m[3]=31;m[4]=30;m[5]=31;
   	m[6]=30;m[7]=31;m[8]=31;m[9]=30;m[10]=31;m[11]=30;m[12]=31;
   	if(d1==m[m1]) cout << 1;
   	else cout << 0;
   	cout << "\n";
    return 0;
}

