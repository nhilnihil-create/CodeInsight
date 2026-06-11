#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N; 
    char S[10001];
    cin >> N;
    scanf("%s", S);
    int len = (int)strlen(S);
    rep(i, len){
        int word = (int)S[i] + N;
        if(word > (int)'Z'){
            word = (int)'A' + (word - (int)'Z' - 1);
        }
        S[i] = (char)word;
    }
    printf("%s\n", S);
    return 0;
}