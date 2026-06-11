#include<iostream>
#include<vector>
using namespace std;

long long n,k,k2;
int a[200005];
int is_visited[200005];

class Loop{
public:
    Loop(int _s, int _st, int _g, int _gt):s(_s),st(_st),g(_g),gt(_gt){}
    int s,st,g,gt;
};

Loop find_loop(int i){
    int next=a[i];
    if(is_visited[next]!=-1){
        int st=is_visited[next];
        int gt=is_visited[i];
        Loop res(next,st,i,gt);
        return res;
    }
    is_visited[next]=is_visited[i]+1;
    return find_loop(next);
}

int main(){
    cin>>n>>k;
    k2=k;
    for(int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
    }
    for(int i=0;i<n;++i) is_visited[i]=-1;
    is_visited[0]=0;
    Loop l=find_loop(0);
    int s=l.s,st=l.st,g=l.g,gt=l.gt;
    long long loop_size=gt-st+1;
    k-=st;
    k%=loop_size;
    int cur=s;
    for(long long i=0;i<k;++i){
        cur=a[cur];
    }

    for(int i=0;i<n;++i){
        if(is_visited[i]==k2){
            cout<<++i<<endl;
            return 0;
        }
    }
    cout<<++cur<<endl;
}