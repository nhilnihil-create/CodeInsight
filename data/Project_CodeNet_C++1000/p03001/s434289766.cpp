#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w, h , x, y;
    cin >> w >> h >> x >> y;

    cout << (w*(h/2.0)) << " ";
    if(x*2 == w && y*2 == h){
        cout << 1 << endl;
    }else{
        cout  << 0 << endl;
    }
}