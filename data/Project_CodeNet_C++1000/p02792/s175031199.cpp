#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    ll n;
    cin >> n;

    string strn = to_string(n);
    int num = strn.length();
    int topn = strn[0]-'0';
    int lastn = strn[num-1]-'0';
    int middle = 0;
    for(int i = 1; i < num-1; i++){
        if(i != 1) middle *= 10;
        middle += strn[i]-'0';
    }
    ll ans = 0;

    for(ll i = 1; i <= n; i++){
        ll cnt = 0;
        ll n_digits = num;
        string str = to_string(i);
        int digits = str.length();
        bool issame = false;
        int top = str[0]-'0';
        int last = str[str.length()-1]-'0';
        if(top == last) issame = true;
        
        if(last == 0) continue;
        if(last > topn){
            n_digits -=1;
        } else if(last == topn && top > lastn && num == 2) continue;
        else if(last == topn && num > 2){
            ll tmp = middle+1;
            if(tmp > 0 && top > lastn) tmp-=1;
            cnt += tmp;
            n_digits -= 1;
        }

        switch(n_digits){
            case 6:
            cnt += 10*10*10*10;
            case 5:
            cnt += 10*10*10;
            case 4:
            cnt += 10*10;
            case 3:
            cnt += 10;
            case 2:
            cnt +=1;
            case 1:
            if(digits == 1 || issame){
                cnt += 1;
            }
            break;
        }
    //    cout << i << ":" << cnt << endl;
        ans += cnt;
    }

    cout << ans << endl;
    return 0;
}