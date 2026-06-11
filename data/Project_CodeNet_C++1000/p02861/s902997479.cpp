#include <bits/stdc++.h>
using namespace std;

int main() {
    double N,x1,x2,y1,y2,total=0,c=0;
    cin >> N;
    vector<pair<int,int>> pos(N);
    vector<int> v(N);
    double kyori;
    for(int i=0;i<N;i++){
        cin >> pos.at(i).first >> pos.at(i).second;
        v.at(i)=i;
    }

    do{
        for(int i=0;i<v.size()-1;i++){
            x1=pos.at(v.at(i)).first;
            y1=pos.at(v.at(i)).second;
            x2=pos.at(v.at(i+1)).first;
            y2=pos.at(v.at(i+1)).second;
            kyori = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            total+=kyori;
        }
        c++;
    }while (next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(10);
    cout << total/c<<endl;
    
}