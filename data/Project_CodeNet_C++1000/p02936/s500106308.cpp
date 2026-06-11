#include <iostream>
#include <vector>
using namespace std;

vector<int> a(200005);
vector<int> b(200005);
vector<int> e[200005];

void dfs(int x){
    b[x] = 1;
    for(int &v : e[x]) {
			if(v == x)
				continue;
            if(b[v]==0){
                a[v] += a[x];
                dfs(v);
            }
		}
    return;
}

int main(){
    int n,q;
    cin >> n >> q;

    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for(int i=0; i<q; i++){
        int p,x;
        cin >> p >> x;
        a[p] += x;
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }

    cout << endl;

}