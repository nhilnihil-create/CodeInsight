#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main ()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //#define int ll
	
    int n, x, y;
    cin >> n >> x >> y;

    vector <vector <int> > distance(n+1, vector <int> (n+1, 0));
    for (int i=1; i<=n; i++){
    	for (int j=1; j<=n; j++){
    		distance[i][j] = abs(i-j);
    // 		cout << distance[i][j] << " ";
    	}
    // 	cout << endl;
    }

    vector <int> cnt(n+3, 0);

    for (int i=1; i<=n; i++){
    	for (int j=1; j<=n; j++){
    		if (i == j) continue;
    		if (distance[i][x] + distance[y][j] + 1 < distance[i][j]){
    			distance[i][j] = distance[j][i] = distance[i][x] + distance[y][j] + 1;
    		}
    	}
    }

    for (int i=1; i<=n; i++){
    	for (int j=1; j<=n; j++){
    		int now = distance[i][j];
    // 		cout << now << " ";
    		if (j < i) continue;
    // 		cnt[1]++;
    // 		cnt[now+1]--;
            cnt[now]++;
    	}
    // 	cout << endl;
    }

    // for (int i=1; i<=n+1; i++){
    // 	cnt[i] += cnt[i-1];
    // }

    for (int i=1; i<n; i++){
    	cout << cnt[i] << endl;
    }

	return 0;
	
}
