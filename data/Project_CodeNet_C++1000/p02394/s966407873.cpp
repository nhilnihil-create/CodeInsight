#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
    int w, h, x, y, r;
    cin >>w >>h >>x >>y >>r;
    int lx,lx2,ly,ly2;
    lx = x+r;
    lx2 = x-r;
    ly = y+r;
    ly2 = y-r;
    if((lx<=w)&&(lx2>=0)&&(ly<=h)&&(ly2>=0)){
      cout <<"Yes\n";
    }
    else{
      cout <<"No\n";
    }
}

