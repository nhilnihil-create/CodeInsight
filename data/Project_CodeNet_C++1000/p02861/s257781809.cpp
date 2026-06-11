#include <bits/stdc++.h>
using namespace std;

int factorial(int k){
    if(k==0) return 1;

    int now=factorial(k-1);
    return k*now;
}

int main() {
    int N; cin >> N;
    vector<int> x(N); vector<int> y(N);
    for(int i=0; i<N; i++){
        cin >> x.at(i) >> y.at(i);
    }
    vector<int> order(N);
    for(int i=0; i<N; i++){
        order.at(i)=i;
    }
    double sum=0;
    do{
        for(int i=0; i<N-1; i++){
            int xnow=x.at(order.at(i+1))-x.at(order.at(i));
            int ynow=y.at(order.at(i+1))-y.at(order.at(i));
            sum=sum+sqrt(xnow*xnow+ynow*ynow);
        }
    }while(next_permutation(order.begin(),order.end()));



    cout << setprecision(7) << sum/factorial(N) << endl;
}

    