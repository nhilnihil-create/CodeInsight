#include <iostream>

using namespace std;

int main()
{
    int x,n;
    int vis_index;
    int vis[105] = {0};
    int left, right;

    cin >> x >> n;
    if(n==0){
        cout << x << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> vis_index;
        vis[vis_index]++;
    }

    left = right = x;
    while(true){
        if(vis[left]==0){
            cout << left << endl;
            break;
        }
        if(vis[right]==0){
            cout << right << endl;
            break;
        }
        left--;
        right++;
    }
    return 0;
}

