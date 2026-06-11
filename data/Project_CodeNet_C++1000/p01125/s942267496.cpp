#include <iostream>
#include <cstdio>
#define MAX 21
using namespace std;

typedef struct {
    int PositionX;
    int PositionY;
    bool field[MAX][MAX];
} Player;

int main() {
    Player xy_player;
    while (true) {
        xy_player.PositionX=10;
        xy_player.PositionY=10;
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                xy_player.field[i][j]=false;
            }
        }
        int N;
        scanf("%d",&N);
        if (N==0) {
            break;
        }
        int x, y;
        for (int i=0; i<N; i++) {
            scanf("%d %d",&x,&y);
            xy_player.field[y][x]=true;
        }
        int M;
        scanf("%d",&M);
        char direction;
        int move;
        for  (int i=0; i<M; i++) {
            cin >> direction >> move;
            switch (direction) {
                case 'N':
                    for (int j=0; j<=move; j++) {
                        xy_player.field[xy_player.PositionY+j][xy_player.PositionX]=false;
                    }
                    xy_player.PositionY+=move;
                    break;
                case 'E':
                    for (int j=0; j<=move; j++) {
                        xy_player.field[xy_player.PositionY][xy_player.PositionX+j]=false;
                    }
                    xy_player.PositionX+=move;
                    break;
                case 'S':
                    for (int j=0; j<=move; j++) {
                        xy_player.field[xy_player.PositionY-j][xy_player.PositionX]=false;
                    }
                    xy_player.PositionY-=move;
                    break;
                case 'W':
                    for (int j=0; j<=move; j++) {
                        xy_player.field[xy_player.PositionY][xy_player.PositionX-j]=false;
                    }
                    xy_player.PositionX-=move;
                    break;
                default:
                    break;
            }
        }
        bool jewelry=true;
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                if (xy_player.field[i][j]==true) {
                    jewelry=false;
                }
            }
        }
        if (jewelry) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}