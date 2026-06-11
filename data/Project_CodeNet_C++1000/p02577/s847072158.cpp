#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

char s[200010];

int main(){

    scanf("%s", s);
    int len = strlen(s);
    int sum = 0;
    for(int i=0; i<len; i++){
        sum += s[i] - '0';
    }
    if(sum % 9 == 0){
        puts("Yes");
    } else{
        puts("No");
    }

    return 0;
}