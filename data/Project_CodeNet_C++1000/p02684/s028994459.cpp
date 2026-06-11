#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int>  foo,s;
typedef long long int ll;
int n;
ll k;
int main()
{
    cin >> n >> k;
    vector<bool> flag(n+1);
    int x, tail,hed;
    foo.push_back(-1);
    s.push_back(-1);
    for (int i = 1; i <=n; ++i) { cin >> x; foo.push_back(x); }
    for (int i = 1;;) {
        if (!flag[foo[i]]) {
            s.push_back(foo[i]);
            flag[foo[i]] = 1;
            i = foo[i];
        }
        else { 
           tail = s.size()-1;
           for (int j = 1; ; ++j) {
                if (s[j] == foo[i]) {
                    hed = j;
                    break;
                }
               
            }
            break;
        }
    }
    int loop = tail - hed+1;
    int ans;
    if (k > tail)
        ans = (k - hed ) % loop+hed;
    else ans = k;
    cout << s[ans] << endl;
    return 0;
}