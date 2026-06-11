#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    
    string S;
    cin >> S;
    
    int a=0;
    int b=(int)S.length()-1;
    int count=0;
    
    while(a<b){
        if(S[a]!=S[b]){
            S[a]=S[b];
            count++;
        }
        a++;
        b--;
    }
    
    cout << count << endl;
    
    return 0;
}
