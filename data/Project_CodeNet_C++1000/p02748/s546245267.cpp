#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,M;
    cin >> A >> B >> M;
    vector<int> a(A),b(B);
    int x,y,c;
    int i;
    int pa=100000,pb=100000;
    int price;

    for(i=0; i<A; i++){
        cin >> a.at(i);
        if(pa>a.at(i)) pa=a.at(i);
    }
    for(i=0; i<B; i++){
        cin >> b.at(i);
        if(pb>b.at(i)) pb=b.at(i);
    }
    price=pa+pb;

    for(i=0; i<M; i++){
        cin >> x >> y >> c;
        if(price>a.at(x-1)+b.at(y-1)-c) price=a.at(x-1)+b.at(y-1)-c;
    }

    cout << price << endl;
}