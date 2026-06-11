#include <algorithm>
#include <iostream>
using namespace std;

int a, b, m, cost;

int main(){
    cin >> a >> b >> m;
    int x[a], y[b];
    for(int i=0; i<a; i++){
        cin >> x[i];
    }
    for(int i=0; i<b; i++){
        cin >> y[i];
    }
    cost = *min_element(x, x+a) + *min_element(y, y+b);
    for(int i=0, idxX, idxY, c; i<m; i++){
        cin >> idxX >> idxY >> c;
        cost = min(cost, x[idxX-1]+y[idxY-1]-c);
    }
    cout << cost << endl;
}
