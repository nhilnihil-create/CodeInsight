#include <bits/stdc++.h>

#define ll long long
#define INF INT_MAX

using namespace std;

int main() {
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }else if(n == 1){
            cout << "1 1" << endl;
            continue;
        }

        //??\???
        vector< pair<int,int> > v = vector< pair<int,int> >(n);
        int nn,dd;
        v[0] = make_pair(0,0);
        for(int i = 1;i < n;i++){
            cin >> nn >> dd;
            int x,y;
            if(dd == 0){        //???
                y = 0,x = -1;
            }else if(dd == 1){  //???
                y = 1,x = 0;
            }else if(dd == 2 ){ //???
                y = 0,x = 1;
            }else{              //???
                y = -1,x = 0;
            }
            y = v[nn].first + y, x = v[nn].second + x;
            v[i] = make_pair(y,x); 
        }

        // for(int i = 0;i < n;i++){
        //     cout << "y:" << v[i].first << " x:" << v[i].second << endl;
        // }

        int maxY,maxX;
        int minY,minX;
        maxY = maxX = 0;
        minY = minX = INF;

        for(int i = 0;i < n;i++){
            int x = v[i].second,y = v[i].first;
            minY = min(minY,y);
            maxY = max(maxY,y);
            minX = min(minX,x);
            maxX = max(maxX,x);
        }

        //cout << maxY - minY + 1 << " " << maxX - minX + 1 << endl;
        printf("%d %d\r\n",maxX - minX + 1,maxY - minY + 1);
    }
	return 0;
}        