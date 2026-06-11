    #include <bits/stdc++.h>
    using namespace std;
    long long MOD=1000000007;
    #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
    typedef long long ll;
    #define pb push_back
    typedef pair<ll,ll> pi;


  //   { //segment trees

  //   map<ll,ll> lazy;

    // void build( ll n , ll *a , ll *tree , ll s , ll e , ll index)
    // {
    //   if(s==e)
    //     tree[index]=a[e];

    //   else
    //   {
    //     ll mid=(s+e)/2;
    //     build(n , a , tree , s , mid , 2*index);
    //     build(n , a , tree , mid+1 , e , 2*index+1);
    //     tree[index]=std::max(tree[2*index], tree[2*index+1]);
    //   }
    //   return;
    // }
    
    // ll query( ll *tree, ll s, ll e ,ll qs, ll qe, ll index)
    // {
    //   if(qe<s || qs>e)
    //     return ll_MIN;

    //   else if(s>=qs && e<=qe)
    //     return tree[index];

    //   ll mid=(s+e)/2;
    //   ll left=query(tree,s,mid,qs,qe,2*index);
    //   ll right=query(tree,mid+1,e,qs,qe,2*index+1);
    //   return std::max(left,right);
    // }

    // void pollupdate(ll  *tree, ll s , ll e , ll i , ll inc , ll index)
    // {
    //   if(i<s || i>e)
    //     return;

    //   if(e==s){
    //     tree[index]+=inc;
    //     return;
    //   }

    //   ll mid=(s+e)/2;
    //   pollupdate(tree,s,mid,i,inc,2*index);
    //   pollupdate(tree,mid+1,e,i,inc,2*index+1);
    //   tree[index]=std::max(tree[2*index],tree[2*index+1]);
    //   return;

    // }

  //   void rangeupdate(ll *tree,ll s,ll e, ll l ,ll r , ll inc, ll index)
  //   {
  //     if(r<s || l>e)
  //       return;

  //     if(e==s)
  //     {
  //       tree[index]+=inc;
  //       return;
  //     }

  //     ll mid=(s+e)/2;
  //     rangeupdate(tree,s,mid,l,r,inc,2*index);
  //     rangeupdate(tree,mid+1,e,l,r,inc,2*index+1);
  //     tree[index]=std::min(tree[2*index],tree[2*index+1]);
  //     return;


  //   }

  //   void lazyupdate(ll *tree,ll s,ll e,ll l,ll r,ll inc,ll index)
  //   {
  //     //resolve
  //     if(lazy[index])
  //     {
  //       tree[index]+=lazy[index];

  //       if(s!=e){
  //         lazy[2*index]+=lazy[index];
  //         lazy[2*index+1]+=lazy[index];
  //       }

  //       lazy[index]=0;
  //     }

  //     //no overlap
  //     if(r<s || l>e)
  //       return;

  //     //complete
  //     if(s>=l && e<=r)
  //     {
  //       tree[index]+=inc;
  //       if(s!=e)
  //       {
  //         lazy[2*index]+=inc;
  //         lazy[2*index+1]+=inc;
  //       }

  //       return;
  //     }

  //     //partial
  //     //call both sides
  //     ll mid=(s+e)/2;
  //     lazyupdate(tree,s,mid,l,r,inc,2*index);
  //     lazyupdate(tree,mid+1,e,l,r,inc,2*index+1);

  //     tree[index]=std::min(tree[index*2],tree[2*index+1]);
  //     return;
  //   }

  //   ll lazyqueries(ll *tree,ll s,ll e,ll l,ll r,ll index)
  //   {
  //      //resolve
  //     if(lazy[index])
  //     {
  //       tree[index]+=lazy[index];

  //       if(s!=e){
  //         lazy[2*index]+=lazy[index];
  //         lazy[2*index+1]+=lazy[index];
  //       }

  //       lazy[index]=0;
  //     }

  //     //no overlap
  //     if(r<s || l>e)
  //       return ll_MAX;

  //      //complete
  //     if(s>=l && e<=r)
  //     {
  //       return tree[index];
  //     }

  //     ll mid=(s+e)/2;
  //     ll left=lazyqueries(tree,s,mid,l,r,2*index);
  //     ll right=lazyqueries(tree,mid+1,e,l,r,2*index+1);

  //     return std::min(left,right);
      
  //   }
  // }//end of segment trees

  

 int main()
  {
     // cout<<"Hi"<<endl;
    ll n;
    cin>>n;
    std::vector<ll> v(n+1,0);

    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j+=i)
            v[j]++;
    }


    ll ans=0ll;
    for(ll i=1;i<=n;i++)
    {
        ans+=i*v[i];
    }

    cout<<ans<<endl;
   

    return 0;


      
  } 