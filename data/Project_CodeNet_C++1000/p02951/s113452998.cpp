#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a-b>c) cout << 0 << endl;
    else cout << c-(a-b) << endl;
    return 0;
}
