#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

unsigned GetDigit(unsigned num){
    return log10(num)+1;
}

int main(){
    int n;
    cin >> n;
    int keta = GetDigit(n);
    int count[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            count[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        int keta = GetDigit(i);
        if(keta == 1){
            count[i][i]++;
        }
        else{
            int first = i % 10;
            int waru = (int)pow(10,keta-1);
            int last = i / waru;
            count[last][first]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << endl;
}