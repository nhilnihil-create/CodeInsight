//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <stdio.h>
//end of libraries ;
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// ll lmax(ll o , ll w) {if(o>w)return o; return w;}
// ll lmin(ll o , ll w) {if(o<w)return o; return w;}
#define LNF 3999999999999999999
#define INF 999999999
#define N 3000003
#define PI 3.14159265359
#define F first
#define S second
#define pb push_back
#define ll long long
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int n ;
string s;
int main(){
fcin;
    cin >> n;
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        int x  = s[i];
        x += n;
        if(x>90){
            x-=90;
            x+=64;
        }
        s[i] = char(x);
    }
    cout << s << "\n";


}