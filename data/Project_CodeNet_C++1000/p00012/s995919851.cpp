#include <iostream>

using namespace std;

int main()
{
	double v0[2], v1[2], v2[2], p[2];	//[0]にx座標、[1]にy座標

	while (cin >> v0[0] >> v0[1] >> v1[0] >> v1[1] >> v2[0] >> v2[1] >> p[0] >> p[1])
	{
		double v0v1[2] = {v1[0]-v0[0], v1[1]-v0[1]},
			   v1v2[2] = {v2[0]-v1[0], v2[1]-v1[1]},
			   v2v0[2] = {v0[0]-v2[0], v0[1]-v2[1]},
			   v0p[2]  = {p[0]-v0[0],  p[1]-v0[1]},
			   v1p[2]  = {p[0]-v1[0],  p[1]-v1[1]},
			   v2p[2]  = {p[0]-v2[0],  p[1]-v2[1]},

			   vv0 = v0v1[0]*v0p[1] - v0v1[1]*v0p[0],
			   vv1 = v1v2[0]*v1p[1] - v1v2[1]*v1p[0],
			   vv2 = v2v0[0]*v2p[1] - v2v0[1]*v2p[0];

		if((vv0>0 && vv1>0 && vv2>0) || (vv0<0 && vv1<0 && vv2<0)) {
			cout << "YES" << endl;
		}else{
			cout << "NO"  << endl;
		}
	}

	return 0;
}