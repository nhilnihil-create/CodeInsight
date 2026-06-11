#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long int ll;
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int>  ac(n,0),wa(n,0);
    vector<int> p(m);
    vector<string> s(m);
    int AC = 0;
    int WA = 0;
    for(int i=0;i<m;i++){
        cin >> p[i] >> s[i];
    }
    for(int i=0;i<m;i++){
        if(s[i] == "WA" && ac[p[i]-1] == 0){
            wa[p[i]-1]++;
        }
        else if(s[i] == "AC" && ac[p[i]-1] == 0){
            ac[p[i]-1] = 1;
        }
    }
    for(int i=0;i<n;i++){
        if(ac[i] == 1) {
            AC++;
            WA += wa[i];
        }
    }
    cout << AC << " " << WA << endl;
    return 0;
}