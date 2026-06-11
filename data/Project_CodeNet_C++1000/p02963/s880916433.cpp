#include <bits/stdc++.h>
#include<string>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>

int main() {
        fio;
        ll s;
        cin>>s;
        int max=1000000000;
        int x3=(max-s%max)%max;
        int y3=(s+x3)/max;
        cout<<0<<" "<<0<<" "<<max<<" "<<1<<" "<<x3<<" "<<y3<<endl;
        

 }

