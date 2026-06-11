#include <iostream>
#include <vector>
using namespace std;

const int A = 1000005;

int gcd(int x, int y){
    int r;
    if(x<y) swap(x,y);
    while(y>0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(A);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        c[a[i]]++;
    }
    bool pairwise = true;
    for(int i=2;i<A;i++){
        int cnt = 0;
        for(int j=i;j<A;j+=i){
            cnt += c[j];
        }
        if(cnt>1){
            pairwise = false;
        }
    }
    if(pairwise){
        cout << "pairwise coprime" << endl;
        return 0;
    }
    
    int g = 0;
    for(int i=0;i<n;i++){
        g = gcd(g, a[i]);
    }
    if(g==1){
        cout << "setwise coprime" << endl;
        return 0;
    }
    cout << "not coprime" << endl;
    return 0;
}
