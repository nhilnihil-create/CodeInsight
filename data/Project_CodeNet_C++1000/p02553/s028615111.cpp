/*
   * * * * *       *        * * * * * * * * * * * * * * * * * * * * * * * *     * * * * * * *               * *               * * * * * * * * * *
   * * * * *      * *       * * * * * * * * * * * * * * * * * * * * * *    *    * * * * * * *              * * *             * ** * * * * * * * * *
   * *           * * *            * *     * *     * *      * *          * * *   * * *       *             * * * *           * * * *       * *    * *
   * * * * *    * * * *           * *     * *     * *       * * * * * * *  * *  * * * * * * *            * * * * *         * *  * *       * * * * *
   * * * * *   * * * * *          * *     * *     * *        * * * * ** *   * * * * * * * * *           * * * * * *       * *   * * * *   * * * *
         * *  * * * * * *   * *   * *     * *     * *       * * * * * * *    * ** *     * * *          * * * * * * *     * *    * * * *   * *  * *
         * * * *       * *  * *   * *     * *     * *      * *          *     * * *     * * *         * *       * * *   * *     * *       * *   * *
   * * * * ** *         * * * * * * * * * * * * * * * * * * * * * * * * *      *  * * * * * * * * * ** *         * * * * *      * * * * * * *    * *
   * * * * * *           * ** * * * * * * * * * * * * * * * * * * * * * *       * * * * * * * * * * * *           * * * *       * * * * * * *     * *
*/
 
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#define ll long long
#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define sz(a) int((a).size())
#define shit while(t--)
#define fr for(int i=0;i<n;i++)
int maxo=1e9+7;
using namespace std;
int arr[95];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,ans=-1000000000000000000;
    cin>>a>>b>>c>>d;
 
    ans=max(ans,a*c);
    ans=max(ans,a*d);
    ans=max(ans,c*b);
    ans=max(ans,d*b);
 
    cout<<ans<<endl;
 
    return 0;
}