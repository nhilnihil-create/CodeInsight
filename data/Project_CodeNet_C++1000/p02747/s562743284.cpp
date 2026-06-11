#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vii;
typedef vector<pair<int,int>> vip;

#define ZOOM ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ff it->first
#define ss it->second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define LOOP_IT(s) for(auto it=(s).begin();it!=(s).end();++it)

int main(int argc, char* argv[])
{
    ZOOM


    string s;
    cin>>s;
    int n = s.size();
    bool f=1;
    if(n==1)
    {
        cout<<"No";
        return 0;
    }
    for(int i=0,j=1;i<n;++i,++j)
    {
        if(s[i] == 'h'&&s[j] == 'i');
        else
        {
            f=0;
            break;
        }
        ++i,++j;
    }
    cout<<(f?"Yes":"No");

    return 0;
}
