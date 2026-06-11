#include <bits/stdc++.h>

// ---------------------------template starts here-------------------------- 

#define int long long int
#define pb push_back
#define MAX INT_MAX
#define F first
#define S second 
#define mp make_pair
#define MIN INT_MIN
#define MOD 1000000007
#define FO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

set <int> s;
bool ar[100001];
void seive() {
    ar[0] = ar[1] = true;

    for(int p=2; p*p<=100001; p++) {
        if(ar[p] == false) {
            for(int i=p*p;i<=100001;i+=p)
                ar[i] = true ;
        }
    }

    for(int p=2;p<=100001;p++) {
        if(ar[p] == false)
            s.insert(p);
    }
}

bool is_palindrome(string str) {
    int len = str.length();
    for(int i=0;i<=len/2;i++) {
        if(str[i] != str[len-1-i])
            return false;
    }
    return true;
}

// --------------------------template ends here------------------------------

void solve() {
    int ar[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;
    cin >> k;
    k--;
    cout << ar[k];    
    return;
}
int32_t main() {
    FO;
    solve();
    return 0;
}