#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 100;

int main(){
    int N;
    int L[MAX];
    int ans = 0;
    
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> L[i];
    }

    for(int i = 0;i < N;i++){
        for(int j = i + 1;j < N;j++){
            for(int k = j + 1;k < N;k++){
                if(L[i] == L[j] || L[j] == L[k] || L[k] == L[i]){
                    continue;
                }
                int l = L[i];
                int m = L[j];
                int s = L[k];

                if(s > m){
                    swap(s,m);
                }
                if(m > l){
                    swap(m,l);
                }
                if(s + m > l){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}