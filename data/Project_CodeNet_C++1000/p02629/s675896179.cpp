#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=(n)-1;i>j-1;i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli n,a=1;
    vector<lli> mod;
    lli i,j,k;
    cin>>n;
    while(1){
        if(pow(26,a)<n){
            n-=pow(26,a);
            a++;
        }
        else{
            break;
        }
    }
//    cout<<"桁数は"<<a<<endl<<"数字は"<<n<<endl;
    n--;
    rep(i,0,a){
        mod.push_back(n%26);
        n/=26;
    }
    rrep(i,0,a){
        char c='a'+mod[i];
        cout<<c;
    }
    cout<<endl;
}
