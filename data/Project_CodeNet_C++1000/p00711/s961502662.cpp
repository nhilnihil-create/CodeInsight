/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1130&lang=jp*/

#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
};

char map[20][21];

int move(const struct point p,int h,int w){
    int count=1;
    map[p.x][p.y]='/';
    for (int i = 0; i < 4; ++i) {
        struct point tmp=p;

        switch (i){
            case 0:
                tmp.x++;
                break;
            case 1:
                tmp.x--;
                break;
            case 2:
                tmp.y++;
                break;
            case 3:
                tmp.y--;
                break;
            default:
                break;
        }
        if (tmp.x<w && tmp.y<h && map[tmp.x][tmp.y]=='.') {
            count+=move(tmp,h,w);
        }
    }
    return count;
}

int main(){
    int w,h;

    while (cin>>w>>h && (w>0 || h>0)){
        struct point start;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin>>map[j][i];
                if(map[j][i]=='@'){
                    start.x=j;
                    start.y=i;
                }
            }
        }
        cout<<move(start,h,w)<<endl;
    }
    return 0;
}