#include <iostream>
#include <string>
#include <queue>
int a[1005][1005];
bool tf[1005][1005];
int p[10][2];
int dirc[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
int w , h , n;
struct node{
    int x , y , step;
};
int bfs(int st_y , int st_x , int en_y , int en_x){
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            tf[i][j] = false;
        }
    }
    tf[st_y][st_x] = true;    
    std::queue <node> que;
    node node0;
    node0.x = st_x , node0.y = st_y , node0.step = 0;
    que.push(node0);
    while(!que.empty()){
        node0 = que.front();
        que.pop();
        if(node0.x == en_x && node0.y == en_y){
            return node0.step;
        }
        for(int i = 0;i < 4;i++){
            node node1;
            node1.y = node0.y + dirc[i][0] , node1.x = node0.x + dirc[i][1] , node1.step = node0.step + 1;
            if(node1.x >= 0 && node1.x < w && node1.y >= 0 && node1.y < h && a[node1.y][node1.x] >= 0 && tf[node1.y][node1.x] == false){
                tf[node1.y][node1.x] = true;
                que.push(node1);
            }
        }
    }
    return 0;
}
int main(){
    std::cin >> h >> w >> n;
    for(int i = 0;i < h;i++){
        std::string s;
        std::cin >> s;
        for(int j = 0;j < w;j++){
            switch(s[j]){
                case 'S':
                    a[i][j] = 0 , p[0][0] = i , p[0][1] = j;
                    break;
                case '.':
                    a[i][j] = 0;
                    break;
                case '1':
                    a[i][j] = 1; p[1][0] = i , p[1][1] = j;
                    break;
                case '2':
                    a[i][j] = 2; p[2][0] = i , p[2][1] = j;
                    break;
                case '3':
                    a[i][j] = 3; p[3][0] = i , p[3][1] = j;
                    break;
                case '4':
                    a[i][j] = 4; p[4][0] = i , p[4][1] = j;
                    break;
                case '5':
                    a[i][j] = 5; p[5][0] = i , p[5][1] = j;
                    break;
                case '6':
                    a[i][j] = 6; p[6][0] = i , p[6][1] = j;
                    break;
                case '7':
                    a[i][j] = 7; p[7][0] = i , p[7][1] = j;
                    break;
                case '8':
                    a[i][j] = 8; p[8][0] = i , p[8][1] = j;
                    break;
                case '9':
                    a[i][j] = 9; p[9][0] = i , p[9][1] = j;
                    break;
                default:
                    a[i][j] = -1;
                    break;
            }
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans += bfs(p[i - 1][0] , p[i - 1][1] , p[i][0] , p[i][1]);
    }
    std::cout << ans << "\n";
    return 0;
}
