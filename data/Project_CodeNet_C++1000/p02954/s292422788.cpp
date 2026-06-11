#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << __LINE__ << " : [" << #x << "] = ["; __print(x)


int main()
{
    string s;
    cin >> s;
    int len = s.length();
    s += '#';
    int a[len+5];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < len; i++) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            int j = i;
            while(j >=0 && s[j] == 'R') j--;
            if(s[j] == 'R') j--;
            int k = i+1;
            while(k < len && s[k] == 'L') k++;
            if(s[k] == 'L') k++;
            a[i] = i-j;
            a[i+1] = k-i-1;
            int x = a[i] + a[i+1];
            // dbg(x);
            if(x%2==0) a[i] = x/2, a[i+1] = x/2;
            else {
                if(a[i+1] > a[i]) {
                    if(a[i+1] % 2) {
                        a[i] = x/2 ;
                        a[i+1] = x - a[i];
                    } else {
                        a[i] = x/2 + 1;
                        a[i+1] = x - a[i];
                    }
                } else {
                    if(a[i] % 2) {
                        a[i+1] = x/2;
                        a[i] = x - a[i+1];
                    } else {
                        a[i+1] = x/2 + 1;
                        a[i] = x - a[i+1];
                    }
                }
            }
        }
    }
    for(int i = 0; i < len; i++) printf("%d ", a[i]);
    puts("");
}
