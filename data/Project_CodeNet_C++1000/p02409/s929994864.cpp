#include<iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int b,f,r,v;
    int rooms[10][10][10];
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int h=0; h<10; h++)
                rooms[i][j][h]=0;
        }
    }
    for(int e=0; e<x; e++){
        cin >> b >> f >> r >> v;
        rooms[b-1][f-1][r-1] += v;
    }
    for(int a=0; a<4; a++){
        for(int b=0; b<3; b++){
            for(int c=0; c<10; c++){
                if(rooms[a][b][c]!=0)
                    cout << ' '<< rooms[a][b][c];
                else
                    cout << ' ' << '0';
                }
            cout << endl;
            }
    if(a != 3) cout << "####################" << endl;
    }
    
    return 0;
}