#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N),Q(N);
    for(int i=0; i<N; i++){
        cin >> P.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> Q.at(i);
    }
    vector<int> order(N);
    for(int i=0; i<N; i++){
        order.at(i)=i+1;
    }
    int a,b;
    int now=1;
    do{
        int cntp=1; int cntq=1;
        for(int i=0; i<N; i++){
            if(order.at(i)!=P.at(i)) cntp=0;
            if(order.at(i)!=Q.at(i)) cntq=0;
        }
        if(cntp==1) a=now;
        if(cntq==1) b=now;
        now++;
    }while(next_permutation(order.begin(),order.end()));
    
    cout << abs(a-b) << endl;
}
