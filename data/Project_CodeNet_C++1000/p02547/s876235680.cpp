#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<list>
#include<cstring>
#include<cctype>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;

    int a[n],b[n];
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }

    int cnt = 0,ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] == b[i]){
            cnt++;
            ans = max(ans,cnt);
            //cout << i << endl;
        } else cnt = 0;
    }
    
    if(ans >= 3)cout << "Yes" << endl;
    else cout << "No" << endl;
}