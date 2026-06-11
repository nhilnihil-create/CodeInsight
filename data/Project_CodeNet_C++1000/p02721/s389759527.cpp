#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 3e5;
const ll bits = 20;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll p = 29;


int main(){

    FASTIO;
    PRECISION; 

    int n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    vector<int>l(k),r(k);
    int i = 0;
    int ptr = 0;
    while(i<n){
        while(i<n && s[i]=='x')i++;
        l[ptr] = i;
        i+=c+1;
        ptr++;
        if(ptr==k) break;
    }
    i = n-1;
    ptr = k-1;
    while(i>=0){
        while(i && s[i]=='x')i--;
        r[ptr] = i;
        i-=c+1;
        ptr--;
        if(ptr==-1) break;
    }

    for(int i=0;i<k;i++){
        if(l[i]==r[i]) cout<<l[i]+1<<"\n";
    }


}
