#include <iostream>

using namespace std;

int main(){
    int e;
    while(cin >> e, e){
        int m = e;
        for(int z=0; z<m && z*z*z<=e; ++z){
            for(int y=0; y+z<m && y*y+z*z*z<=e; ++y){
                int x = e - z*z*z - y*y;
                if(x + y + z < m)m = x + y + z;
            }
        }
        cout << m << '\n';
    }
    return 0;
}