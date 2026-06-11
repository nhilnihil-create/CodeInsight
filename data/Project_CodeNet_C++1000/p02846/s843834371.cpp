#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
	ll t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	
	//Fuck calculations. Try with Relativity.
	ll rel_dist_1 = t1*(a1-b1);
	ll rel_dist_2 = t2*(a2-b2);
	
	//Cover first distance as positive no matter what...
	if(rel_dist_1 < 0)
	{
		rel_dist_1 *= -1;
		rel_dist_2 *= -1;
	}
	
	//Now see total_dist_covered...
	ll total_rel_dist_covered = rel_dist_1 + rel_dist_2;
	
	if(total_rel_dist_covered==0)
	{
		cout<<"infinity\n";
	}
	else if(total_rel_dist_covered > 0)
	{
		cout<<0<<endl;
	}
	else
	{
		//How many times do we meet now?
		//Can I somehow find a relation between them?
		total_rel_dist_covered *= -1;
		/* rd1 -rd2 where rd2>rd1...so now rd = rd2-rd1
		 * If I move ahead by 2rd1, i'll be pulled back by one rd2.
		 * ...-3 -2 -1 0 1 2 3 4...
		 * Find with repeated tug of war...+X & -Y, when do I finally become permanent negative.
		 * Pull is from +X to 0 => X
		 * Force doing the pull = Y-X
		 * Simulate a +X, -Y, +X, -Y, +X, -Y until finally doing +X no longer gives me a positive value.
		 * so umm...let us combine +X and -Y => X-Y, X-Y, X-Y...k times
		 * k(X-Y) = X
		 * or k = (X/(X-Y))
		 * and 2k would give me the times met. If there is remainder, 1 last push was needed.
		 * Therefore: X/(Y-X) will give me
		 */
		ll Q = (rel_dist_1)/(total_rel_dist_covered);
		ll R = (rel_dist_1)%(total_rel_dist_covered);
		//cout<<rel_dist_1<<" "<<total_rel_dist_covered<<endl;
		if(R==0)
			cout<<2*Q<<endl;
		else
			cout<<2*Q+1<<endl;
	}
	return 0;
}
