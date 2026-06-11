#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define px(x) cout << x << endl
#define pfi(x) printf("%d\n", x)
#define pfs(x) printf("%s\n", x)
#define sfi(x) scanf("%d", &x)
#define sfs(x) scanf("%s", x)




int main(int argc, char const *argv[])
{   
   
    int n;
    cin >> n;
        
    string s;
    int t;
    int sum = 0;
    vector<pair<string,int>> vec;


    for(int i=0; i<n; i++){
        cin >> s >> t;
        vec.pb(mp(s,t));
        sum += t;
    }

    string x;
    cin >> x;
    int len = vec.size();
    int nsum = 0;

    for(int i=0; i<len; i++){
        if(vec[i].first == x){
            nsum += vec[i].second;
            break;
        }else{
            nsum += vec[i].second;
            //cout << nsum << " " << endl;
        }
    }

    cout << sum-nsum << endl;
























    return 0;
}