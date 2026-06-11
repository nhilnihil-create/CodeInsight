#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    double count = 0;
    for(int i = 1; i <= N; i++){
        if(i % 2 != 0) count++;
    }
    
    double ans = count / (double)N;
    printf("%.10lf\n",ans);
}