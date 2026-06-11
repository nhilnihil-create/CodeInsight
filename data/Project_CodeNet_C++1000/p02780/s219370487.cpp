#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<double> p(N);
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        p[i] = (double)(num+1)/2;
    }
    double S=0,S_k;
    for(int i=0; i<N; i++){
        S+=p[i];
        if(i==N-1-K)S_k=S;
    }
    int i = N-1, j = i-K;
    double maxi = 0;
    while(1){
        maxi = max(maxi,S-S_k);
        if(j==-1) break;
        S -= p[i--];
        S_k -= p[j--];
    }
    printf("%f\n",maxi);
}