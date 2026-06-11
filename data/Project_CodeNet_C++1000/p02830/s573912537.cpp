#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++);
using namespace std;
using ll = long long;

int main() {
    int n;
    char s[105],t[105],str[210];
    cin >> n;

    scanf("%s %s/n",s,t);

    for (int i = 0; i <= (int)(n); i++){
        str[2*i]=s[i];
        str[2*i+1]=t[i];
    }

    printf("%s",str);
}