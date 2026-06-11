//Only the Creator has given me strength!

#include<cstdio>

#include<sstream>

#include<cstdlib>

#include<cctype>

#include<cmath>

#include<algorithm>

#include<set>

#include<queue>

#include<stack>

#include<list>

#include<iostream>

#include<fstream>

#include<numeric>

#include<string>

#include<vector>

#include<cstring>

#include<map>

#include<iterator>

#include<bitset>

typedef long long ll;

#define pi 3.1415926535897931159979635

#define pb push_back

#define vctr vector < int >

#define vvtr vector < vctr >

using namespace std;

ll mod=1e7+7;

void fastio() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

}

int main() {

    fastio();

    string a;

    cin>>a;

    int s=a.size();

    if(a[s-1]=='s') cout<<a<<"es\n";

    else cout<<a<<"s\n";

    return 0;

}