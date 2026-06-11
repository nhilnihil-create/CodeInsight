#include<iostream>
using namespace std;
typedef long long int ll;
#define graphsize 2000007

ll tree[graphsize];
ll arr[graphsize];

ll buildtree(ll left,ll right,ll index){
    if(left==right){
        tree[index] = arr[left];
        return arr[left];
    }

    ll mid = left +((right-left)/2);
    ll leftsum = buildtree(left,mid,index*2);
    ll rightsum = buildtree(mid+1,right,index*2+1);
    tree[index]=leftsum+rightsum;
    return tree[index];
}

void update(ll left,ll right,ll index,ll value,ll currindex){
    if(left==right && left==currindex){
        tree[index]+=value;
        return;
    }

    if(left==right){
        return;
    }

    

    ll mid = left+((right-left)/2);
    tree[index]+=value;
    if(currindex<=mid){
        update(left,mid,index*2,value,currindex);
    }else{
        update(mid+1,right,index*2+1,value,currindex);
    }
    return;
}

ll query(ll left,ll right,ll index,ll start,ll end){
    if(left>end || right<start){
        return 0;
    }
    if(left>=start&&right<=end){
        return tree[index];
    }
    if(left==right){
        return tree[index];
    }

    ll mid = left+((right-left)/2);
    ll leftq = query(left,mid,index*2,start,end);
    ll rightq = query(mid+1,right,index*2+1,start,end);
    return leftq+rightq;
    
}

int main(){
    ll n,q,a,b,c;
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildtree(1,n,1);
    for(ll i=0;i<q;i++){
        cin>>a>>b>>c;
        if(a==0){
            update(1,n,1,c,b+1);
        }else{
            cout<<query(1,n,1,b+1,c)<<endl;
        }
    }
}