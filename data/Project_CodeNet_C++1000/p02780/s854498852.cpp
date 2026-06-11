#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<int> p(200010);
vector<double> CSum_p(200010, 0);  //i番目までのpの和
double res = 0;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){ cin >> p[i]; CSum_p[i+1]=p[i]+CSum_p[i]; }
    for(int i = K; i <= N; i++) res=max(res,((CSum_p[i]-CSum_p[i-K]+K)/2)); 
    printf("%.12f\n", res);
    return 0;
}