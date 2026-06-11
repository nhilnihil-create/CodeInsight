#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

#define fin             freopen("input.txt","r",stdin);
#define fout            freopen("output.txt","w",stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int c=0,n;
    cin >> n >> s;

    for(int i = 0;i<n;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')c++;
    }
    cout << c << endl;
    return 0;
}

