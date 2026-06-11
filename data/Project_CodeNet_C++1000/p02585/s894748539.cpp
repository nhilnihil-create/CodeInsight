#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<long> p;
vector<long> c;

int main(){
    long n,k;
    cin >> n >> k;

    p.resize(n);
    c.resize(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0;i < n;i++){
        cin >> c[i];
    }
    long ans = LONG_MIN;

    vector<long> round(n);//何回回れば元の位置に戻るか
    for(int i = 0;i < n;i++){
        long cycle = 0;
        long sum = 0;
        int v = i;
        //i始まりで何回回れば1周できるかと1周回った際の合計
        while(true){
            cycle++;
            sum += c[v];
            v = p[v];
            if(v == i){
                break;
            }
        }
        long path = 0;
        long cnt = 0;

        while(true){
            cnt++;
            path += c[v];

            if(cnt > k)break;
            long num = (k - cnt) / cycle;
            long score = path + max(0l,sum) * num;
            ans = max(ans,score);
            v = p[v];
            if(v == i)break;
        }

        
    }
    cout << ans << endl;
    


    return 0;
}